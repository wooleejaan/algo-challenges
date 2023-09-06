class Table {
  count = 0;
  _table = new Array(50)
    .fill(0)
    .map(() => new Array(50).fill(0).map(() => ({})));

  getCell(r, c) {
    return this._table[r - 1][c - 1];
  }
  // "UPDATE r c value"
  setCell(r, c, value) {
    this._table[r - 1][c - 1] = value;
  }
  // "UPDATE value1 value2"
  update(...params) {
    if (params[2] != null) {
      const [r, c, value] = params;
      const cell = this.getCell(r, c);
      cell.value = value;
    } else {
      const [value1, value2] = params;

      this._table.forEach((row) => {
        row.forEach((cell) => {
          if (cell && cell.value === value1) cell.value = value2;
        });
      });
    }
  }
  _replaceCell(cell1, cell2) {
    this._table = this._table.map((row) =>
      row.map((cell) => (cell === cell1 ? cell2 : cell))
    );
  }
  // "MERGE r1 c1 r2 c2"
  merge(r1, c1, r2, c2) {
    const cell1 = this.getCell(r1, c1);
    const cell2 = this.getCell(r2, c2);

    if (cell1.value == null) {
      this._replaceCell(cell1, cell2);
    } else {
      this._replaceCell(cell2, cell1);
    }
  }
  // "UNMERGE r c"
  unmerge(r, c) {
    const cell = this.getCell(r, c);

    this._table = this._table.map((row) => {
      return row.map((cl) => (cl == cell ? {} : cl));
    });
    this.setCell(r, c, cell);
  }

  print(r, c) {
    return this.getCell(r, c).value || "EMPTY";
  }
}

function solution(commands) {
  const table = new Table();
  const answer = [];

  commands.forEach((line) => {
    const [command, ...params] = line.split(" ");
    const result = table[command.toLowerCase()](...params);
    if (result) answer.push(result);
  });
  return answer;
}