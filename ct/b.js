function solution(play_list, listen_time) {
  let answer = 0;
  let flated = [];
  play_list.forEach((p) => flated.push(...new Array(p).fill(p)));
  flated = [...flated, ...flated.slice(0, listen_time - 1)];
  for (let i = 0; i < flated.length - listen_time + 1; i++) {
    const splited = flated.slice(i, i + listen_time);
    answer = Math.max(answer, new Set(splited).size);
  }
  return answer;
}

console.log(solution([2, 3, 1, 4], 3));
console.log(solution([1, 2, 3, 4], 5));
console.log(solution([1, 2, 3, 4], 20));
