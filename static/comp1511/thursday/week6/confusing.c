// Test if a point is inside a triangle.
// Julian Saknussemm
//
// Given Three points of a triangle, and another arbitrary point this program determines if that point lies inside
// the triangle.
//
// This is determined by satisfying the following rule:
// A point P(x,y) is inside triangle A(x0,y0), B(x1,y1), C(x2,y2)
// iff
// P is on the same side of the line AB as C
// P is on the same side of the line BC as A
// and
// P is on the same side of the line AC as B
//
// A special case exits for a vertical line (inf gradient) when testing the side of the line

#include <stdio.h>
#define UNDER_LINE -1
#define ON_LINE 0
#define OVER_LINE 1
#define EXPECTED_NUM_VALUES 8

// point py, px is on the line
int lineTest( double px, double py, double m, double b )
{
   if (py < m * px + b) {
      // point is under line
      return UNDER_LINE;
   } else if ( py == m * px + b ) {
      // point is on the line
      return ON_LINE;
   }

   return OVER_LINE;
}

// two points lie on the same side of a line
int sameSection( double px, double py, double m, double b,
                 double lx, double ly) {
        return (lineTest(px,py, m, b) == lineTest(lx, ly, m, b));
}

int tritest(double x0,double y0,double x1,double y1,double x2,double y2,double px, double py){

    int line1, line2, line3;
`   // line eqns

   double m01 = (y1-y0)/(x1-x0);
   // b: y - y1 = m( x - x1 ), x = 0
   double b01 = m01 * -x1 + y1;
   double m02, m12, b02, b12;
   m02 = (y2-y0)/(x2-x0);
   m12 = (y2-y1)/(x2-x1);
   b02 = m02 * -x2 + y2;
   b12 = m12 * -x2 + y2;

   // vertical line checks
   if( x1 == x0 ) {
      line1 = ( (px <= x0) == (x2 <= x0) );
   } else {
      line1 = sameSection( px, py, m01, b01,x2,y2);
   }

   if( x1 == x2 ) {
           line2 = ( (px <= x2) == (x0 <= x2) );
   } else {
           line2 = sameSection(px,py, m12, b12,x0,y0);
   }

   if( x2 == x0 ) {
   line3 = ( (px <= x0 ) == (x1 <= x0) );} else {
           line3 = sameSection(px, py, m02,b02,x1,y1);
   }`

   return line1 && line2 && line3;

}
int main(int argc, char* argv[]) {
   double x0,y0,x1,y1,x2,y2,px;
   double py;

   int numValuesScanned = 0;

   // get input
   printf("Triangle Vertex A (x,y): ");
   numValuesScanned += scanf("%lf,%lf", &x0,&y0);
   printf("Triangle Vertex  B (x,y): ");
   numValuesScanned += scanf("%lf,%lf", &x1,&y1);
   printf("Triangle Vertex  C (x,y): ");
   numValuesScanned += scanf("%lf,%lf", &x2,&y2);
   printf("Test Point (x,y): ");
   numValuesScanned += scanf("%lf,%lf", &px,&py);

   // print error
   if( numValuesScanned != EXPECTED_NUM_VALUES ) {
      printf("Bad luck, program is now exiting!\n");
      return 1;
   }

   // print answer
   printf("Point (%.2lf,%.2lf) is ", px,py);
   if(tritest(x0,y0,x1,y1,x2,y2,px,py)) printf("inside");
   else printf("outside");
   printf(" the Triangel\n");

   // return 0
   return 0;
}
