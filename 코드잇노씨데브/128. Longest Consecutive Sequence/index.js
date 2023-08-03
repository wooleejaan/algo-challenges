const longestConsecutive = (nums) => {
  nums.sort((a, b) => a - b);
  let count = 0;
  let temp = 1;
  if (nums.length <= 1) return nums.length;

  for (let i = 0; i < nums.length - 1; i++) {
    if (nums[i] === nums[i + 1] - 1) {
      temp++;
      count = Math.max(count, temp);
      continue;
    } else if (nums[i] === nums[i + 1]) {
      count = Math.max(count, temp);
      continue;
    }
    temp = 1;
    count = Math.max(count, temp);
  }
  return count;
};

console.log(longestConsecutive([1, 2, 0, 1])); // 3
console.log(longestConsecutive([100, 4, 200, 1, 3, 2])); // 4
console.log(longestConsecutive([0, 3, 7, 2, 5, 8, 4, 6, 0, 1])); // 9
