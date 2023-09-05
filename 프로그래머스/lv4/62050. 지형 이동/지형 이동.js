const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];

class UnionFind {
  constructor(n) {
    this.parents = Array.from({ length: n }, (_, i) => i);
  }

  getParent(num) {
    if (num === this.parents[num]) return num;
    return (this.parents[num] = this.getParent(this.parents[num]));
  }
  find(a, b) {
    const aParent = this.getParent(a);
    const bParent = this.getParent(b);

    return aParent === bParent;
  }
  unionParent(a, b) {
    const aParent = this.getParent(a);
    const bParent = this.getParent(b);

    if (aParent > bParent) this.parents[aParent] = bParent;
    else this.parents[bParent] = aParent;
  }
}

function devideToIsland(N, land, height) {
  const devidedIsland = Array.from({ length: N }, () => []);

  let number = 0;
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if (!devidedIsland[i][j]) {
        number += 1;
        devidedIsland[i][j] = number;
        const queue = [[i, j]];
        let index = 0;

        while (queue.length > index) {
          const [y, x] = queue[index++];

          for (let k = 0; k < 4; k++) {
            const nx = x + dx[k];
            const ny = y + dy[k];

            if (
              nx >= 0 &&
              ny >= 0 &&
              nx < N &&
              ny < N &&
              !devidedIsland[ny][nx]
            ) {
              if (height >= Math.abs(land[y][x] - land[ny][nx])) {
                devidedIsland[ny][nx] = number;
                queue.push([ny, nx]);
              }
            }
          }
        }
      }
    }
  }
  return [devidedIsland, number];
}

function implEdges(N, land, devidedIsland) {
  const edges = [];
  const visited = Array.from({ length: N }, () => Array(N).fill(false));
  visited[0][0] = true;

  const queue = [[0, 0]];
  let index = 0;

  while (queue.length > index) {
    const [y, x] = queue[index++];

    for (let i = 0; i < 4; i++) {
      const nx = x + dx[i];
      const ny = y + dy[i];

      if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
        const nowVertex = devidedIsland[y][x];
        const nextVertex = devidedIsland[ny][nx];
        const weight = Math.abs(land[y][x] - land[ny][nx]);

        if (nowVertex !== nextVertex) {
          edges.push([nowVertex, nextVertex, weight]);
          edges.push([nextVertex, nowVertex, weight]);
        }

        if (!visited[ny][nx]) {
          visited[ny][nx] = true;
          queue.push([ny, nx]);
        }
      }
    }
  }

  return edges;
}

function solution(land, height) {
  let answer = 0;
  const N = land.length;

  const [devidedIsland, islandCnt] = devideToIsland(N, land, height);
  const edges = implEdges(N, land, devidedIsland);

  const uf = new UnionFind(islandCnt + 1);

  edges.sort((a, b) => a[2] - b[2]);

  let cnt = 0;
  for (let i = 0; i < edges.length; i++) {
    const [from, to, cost] = edges[i];

    if (!uf.find(from, to)) {
      answer += cost;
      uf.unionParent(from, to);
      cnt += 1;
    }

    if (cnt === islandCnt - 1) break;
  }
  return answer;
}