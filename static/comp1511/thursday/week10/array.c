int size = 10;
int myarray[size];

for (int i = 0; i < size; i ++) {
   myarray[i] = 0;
}

myarray[HAND_SIZE] = {0};

int *my_array = calloc(size, sizeof(int));
int *my_array = malloc(size*sizeof(int));
