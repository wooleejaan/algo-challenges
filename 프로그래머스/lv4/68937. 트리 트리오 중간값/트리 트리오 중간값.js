class CustomQueue {
  constructor() {
    this.storage = {};
    this.front = 0;
    this.rear = 0;
  }

  size() {
    if (this.storage[this.rear] === undefined) return 0;
    return this.rear - this.front + 1;
  }

  add(val) {
    if (this.size() === 0) {
      this.storage["0"] = val;
    } else {
      this.rear += 1;
      this.storage[this.rear] = val;
    }
  }

  pop() {
    let temp;
    if (this.front === this.rear) {
      temp = this.storage[this.front];
      delete this.storage[this.front];
      this.front = 0;
      this.rear = 0;
      return temp;
    } else {
      temp = this.storage[this.front];
      delete this.storage[this.front];
      this.front += 1;
      return temp;
    }
  }
}

const bfs = (tree, node) => {
  const queue = new CustomQueue();
  const dist = new Array(tree.length).fill(Infinity);
  const visited = new Array(tree.length).fill(false);

  dist[node] = 0;
  visited[node] = true;
  queue.add(node);

  let maxLength = 0;
  let maxIdx = 0;
  let count = 0;

  while (queue.size()) {
    const cur = queue.pop();
    const distance = dist[cur];

    for (const next of tree[cur]) {
      if (!visited[next]) {
        const newDistance = distance + 1;
        visited[next] = true;
        dist[next] = newDistance;
        queue.add(next);

        if (maxLength < newDistance) {
          maxLength = newDistance;
          maxIdx = next;
          count = 1;
        } else if (maxLength === newDistance) {
          count++;
        }
      }
    }
  }

  return [maxLength, maxIdx, count];
};

function solution(n, edges) {
  const tree = new Array(n).fill().map((_) => []);

  for (const [from, to] of edges) {
    tree[from - 1].push(to - 1);
    tree[to - 1].push(from - 1);
  }

  let [leafDist, leafIdx, leafCount] = bfs(tree, 0);

  [leafDist, leafIdx, leafCount] = bfs(tree, leafIdx);

  if (leafCount > 1) return leafDist;

  [leafDist, leafIdx, leafCount] = bfs(tree, leafIdx);

  if (leafCount > 1) return leafDist;

  return leafDist - 1;
}