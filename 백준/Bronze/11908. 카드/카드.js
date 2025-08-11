const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');

let n = Number(input[0]);
let arr = input[1].split(' ').map(Number);
arr.sort((a, b) => a - b);

let res = 0;
for (let i = 0; i<n-1; i++) res += arr[i];
console.log(res);
