const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');

let m = Number(input[0]);
let n = Number(input[1]);

let tot = 0;
let mn = n+1;
let arr = new Array(n + 1).fill(1);
arr[0] = arr[1] = 0;
for (let i = 2; i<=n; i++) {
    if (arr[i] === 1) {
        for (let j = i*i; j<=n; j+=i) arr[j] = 0;
    }
}

for (let i = m; i<=n; i++) {
    if (arr[i] === 1) {
        tot += i;
        mn = Math.min(mn, i);
    }
}
if (tot === 0) console.log(-1);
else {
    console.log(tot);
    console.log(mn);
}