function solution(land, P, Q) {
  // variables and functions
  const N = land.length;
  const arr = [];
  let answer = Infinity;

  const getCost = (height, arr) => {
    let cost = 0;

    for (let i = 0; i < arr.length; i++) {
      if (height < arr[i]) {
        cost += (arr[i] - height) * Q;
      } else if (height > arr[i]) {
        cost += (height - arr[i]) * P;
      }
    }

    return cost;
  };

  const binarySearch = (arr) => {
    const height = [...new Set(arr)];
    let front = 0;
    let back = height[height.length - 1];

    while (front <= back) {
      const mid = Math.floor((front + back) / 2);
      const cost1 = getCost(mid, arr);
      const cost2 = getCost(mid + 1, arr);

      if (cost1 <= cost2) {
        back = mid - 1;
      } else {
        front = mid + 1;
      }

      answer = Math.min(answer, cost1, cost2);
    }
  };

  // start
  for (let i = 0; i < N; i++) {
    arr.push(...land[i]);
  }

  arr.sort((a, b) => a - b);

  binarySearch(arr);

  return answer;
}