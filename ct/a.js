function isCorrectString(s) {
  const stk = [];
  for (let i = 0; i < s.length; i++) {
    if (s[i] === "(" || s[i] === "[" || s[i] === "{") {
      stk.push(s[i]);
    } else {
      if (
        (stk[stk.length - 1] === "(" && s[i] === ")") ||
        (stk[stk.length - 1] === "[" && s[i] === "]") ||
        (stk[stk.length - 1] === "{" && s[i] === "}")
      ) {
        stk.pop();
      }
    }
  }

  return stk.length === 0;
}

function whatIsDeleted(str) {
  let ret = "";
  let strMap2 = {
    s: "()",
    m: "{}",
    l: "[]",
  };
  let strMap = {
    s: 0,
    m: 0,
    l: 0,
  };

  for (let i = 0; i < str.length; i++) {
    if (str[i] === "(") strMap["s"]++;
    if (str[i] === ")") strMap["s"]--;
    if (str[i] === "{") strMap["m"]++;
    if (str[i] === "}") strMap["m"]--;
    if (str[i] === "[") strMap["l"]++;
    if (str[i] === "]") strMap["l"]--;
  }

  for (const key in strMap) {
    if (strMap[key] === 0) continue;
    if (strMap[key] === 1) ret = strMap2[key][1];
    if (strMap[key] === -1) ret = strMap2[key][0];
  }
  return ret;
}

function solution(s) {
  let answer = 0;
  const deletedStr = whatIsDeleted(s);

  for (let i = 0; i <= s.length; i++) {
    const cc = s.slice(0, i) + deletedStr + s.slice(i);
    if (isCorrectString(cc)) answer++;
  }
  return answer;
}

console.log(solution("[]([[]){}")); // expected answer : 3
console.log(solution("{([()]))}")); // expected answer : 4
console.log(solution("(()()()")); // expected answer : 7
