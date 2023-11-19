function cases(n) {
  return (n * (n + 1)) / 2;
}

function cases2(n) {
  let temp = 1;
  for (let i = 2; i <= n; i++) {
    temp *= i;
  }
  return temp;
}

console.log(cases(4), cases2(4));
