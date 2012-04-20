#include "OFF.h"

// parser adaptat de la
// http://shape.cs.princeton.edu/benchmark/

CMesh * OFF::ReadFileMesh(const char *filename) {
    CMesh *mesh;
    int i;

    // Open file
    FILE *fp;
    if (!(fp = fopen(filename, "r"))) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return 0;
    }

    int nverts = 0;
    int nfaces = 0;
    int nedges = 0;
    int line_count = 0;

    // Read file
    char buffer[1024];
    while (fgets(buffer, 1023, fp)) {
        // Increment line counter
        line_count++;

        // Skip white space
        char *bufferp = buffer;
        while (isspace(*bufferp)) bufferp++;

        // Skip blank lines and comments
        if (*bufferp == '#') continue;
        if (*bufferp == '\0') continue;

        // Check section
        if (nverts == 0) {
            // Read header
            if (!strstr(bufferp, "OFF")) {
                // Read mesh counts
                if ((sscanf(bufferp, "%d%d%d", &nverts, &nfaces, &nedges) != 3) || (nverts == 0)) {
                    fprintf(stderr, "Syntax error reading header on line %d in file %s\n", line_count, filename);
                    fclose(fp);
                    return NULL;
                }

                mesh = new CMesh(nverts, nfaces);
                if (!mesh) {
                    fprintf(stderr, "Unable to allocate memory for file %s\n", filename);
                    fclose(fp);
                    return 0;
                }
                assert(mesh->verts);
                assert(mesh->faces);
            }
        } else if (mesh->nverts < nverts) {
            // Read vertex coordinates
            Vector3D vert = Vector3D();
            if (sscanf(bufferp, "%f%f%f", &(vert.x), &(vert.y), &(vert.z)) != 3) {
                fprintf(stderr, "Syntax error with vertex coordinates on line %d in file %s\n", line_count, filename);
                fclose(fp);
                return NULL;
            }
            mesh->AddVertex(&vert);
        } else if (mesh->nfaces < nfaces) {
            // Get next face

            int faceverts;
            // Read number of vertices in face
            bufferp = strtok(bufferp, " \t");
            if (bufferp) faceverts = atoi(bufferp);
            else {
                fprintf(stderr, "Syntax error with face on line %d in file %s\n", line_count, filename);
                fclose(fp);
                return NULL;
            }

            CMesh::Face *face = new CMesh::Face(faceverts);

            // Allocate memory for face vertices
            assert(face->verts);

            // Read vertex indices for face
            for (i = 0; i < face->maxverts; i++) {
                bufferp = strtok(NULL, " \t");
                if (bufferp) face->AddVertex(&(mesh->verts[atoi(bufferp)]));
                else {
                    fprintf(stderr, "Syntax error with face on line %d in file %s\n", line_count, filename);
                    fclose(fp);
                    return NULL;
                }
            }

            // Compute normal for face
            face->normal.x = 0;
            face->normal.y = 0;
            face->normal.z = 0;

            for (i = 0; i < face->nverts; i++) {
                Vector3D *v1 = face->verts[i];
                Vector3D *v2 = face->verts[(i + 1) % face->nverts];
                face->normal.x += (v1->y - v2->y) * (v1->z + v2->z);
                face->normal.y += (v1->z - v2->z) * (v1->x + v2->x);
                face->normal.z += (v1->x - v2->x) * (v1->y + v2->y);
            }

            // Normalize normal for face
            float squared_normal_length = 0.0;
            squared_normal_length += face->normal.x * face->normal.x;
            squared_normal_length += face->normal.y * face->normal.y;
            squared_normal_length += face->normal.z * face->normal.z;
            float normal_length = sqrt(squared_normal_length);
            if (normal_length > 1.0E-6) {
                face->normal.x /= normal_length;
                face->normal.y /= normal_length;
                face->normal.z /= normal_length;
            }
            mesh->AddFace(face);
        } else {
            // Should never get here
            fprintf(stderr, "Found extra text starting at line %d in file %s\n", line_count, filename);
            break;
        }
    }

    // Check whether read all faces
    if (nfaces != mesh->nfaces) {
        fprintf(stderr, "Expected %d faces, but read only %d faces in file %s\n", nfaces, mesh->nfaces, filename);
    }

    // Close file
    fclose(fp);

    mesh->GetCenter();
    mesh->GetDimensions();

    // Return mesh
    return mesh;
}
