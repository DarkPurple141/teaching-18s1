

struct complex_number {
   double real;
   double imaginary;
}

double magnitude(struct complex_number c) {
   sqrt(c.real*c.real + c.imaginary*c.imaginary)
}

double mag = magnitude(my_comple);


struct complex_number add(struct complex_number a, struct complex_number b) {
   return {
      a.real + b.real,
      a.imaginary + b.imaginary
   }
}
