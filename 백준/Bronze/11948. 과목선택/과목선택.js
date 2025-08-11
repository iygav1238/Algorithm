const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');

let a = Number(input[0]);
let b = Number(input[1]);
let c = Number(input[2]);
let d = Number(input[3]);
let e = Number(input[4]);
let f = Number(input[5]);

let res = a + b + c + d + e + f - Math.min(a, b, c, d) - Math.min(e, f);
console.log(res);