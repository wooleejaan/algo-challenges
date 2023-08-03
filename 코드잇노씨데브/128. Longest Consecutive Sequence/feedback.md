#### 접근 방법

nums를 반복하기 전에, 뒤에 더 큰 숫자가 배치되는 걸 막기 위해 정렬을 해줍니다.

그리고 나서, forEach로 반복문을 진행하면서 값이 연속된다면 1씩 더해주는 방식으로 숫자들이 연속된다는 걸 추적합니다.

마지막으로 객체의 값에 저장된 값들 중 최대값을 반환해서 정답을 도출합니다.

#### 코드 작성

내 풀이

```js
const longestConsecutive = (nums) => {
  if (nums.length === 0) return 0;
  nums.sort((a, b) => a - b);
  const tree = {};

  nums.forEach((num) => {
    if (tree[num - 1]) {
      tree[num] = tree[num - 1] + 1;
      return;
    }
    tree[num] = 1;
  });
  return Math.max(...Object.values(tree));
};
```

#### 배우게 된 점 (`풀어보고, 효율적인 풀이와 비교해 깨달은 점을 작성해두었습니다. 틀린 점이 있거나 보충이 필요하다면 피드백해주세요!`)

- 최대값을 도출하는 데 있어 하나의 변수로 관리하지 않고, 객체에 값을 저장하고 Object.values로 꺼내는 과정이 비효율적이었다.

다른 사람의 풀이

```js
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
```
