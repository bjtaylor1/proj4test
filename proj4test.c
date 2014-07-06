#include <proj_api.h>
#include <stdio.h>

       main(int argc, char **argv) {
            projPJ pj_merc, pj_latlong;
            double x, y;
            int p;

            printf("Creating projections...\n");

            if (!(pj_merc = pj_init_plus("+proj=tmerc +lat_0=49 +lon_0=-2 +k=0.9996012717 +x_0=400000 +y_0=-100000 +ellps=airy +datum=OSGB36 +units=m +no_defs")) ) {
              printf("Failed to create first projection\n");
               exit(1);
            }
            printf("Created first projection\n");
            if (!(pj_latlong = pj_init_plus("+proj=longlat +ellps=WGS84 +datum=WGS84 +no_defs")) ) {
              printf("Failed to create second projection\n");
               exit(1);
            }
            printf("Created second projection\n");

            while (scanf("%lf %lf", &x, &y) == 2) {
               x *= DEG_TO_RAD;
               y *= DEG_TO_RAD;
               p = pj_transform(pj_latlong, pj_merc, 1, 1, &x, &y, NULL );
               printf("%.2f\t%.2f\n", x, y);
            }
            exit(0);
       }

