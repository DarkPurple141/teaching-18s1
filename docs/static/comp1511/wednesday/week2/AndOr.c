

/* In C, 0 is 'falsey' and
ANY other number is truthy*/

// So

1 && 2 // True
0 && 1 // False
1 || 2 // True
0 || 0 // False
0 || 1 // True

// Any thuthy statement is evaluated by an if()

// So

if (1) {
   // this will always be evaluated
}

if (0) {
   // this will never be evaluated
}
