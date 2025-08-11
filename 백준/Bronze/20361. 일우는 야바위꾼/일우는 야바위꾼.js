const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');

let [n, x, k] = input[0].split(' ').map(Number);
for (let i = 1; i<=k; i++) {
    const [a, b] = input[i].split(' ').map(Number);
    if (a == x) x = b;
    else if (b == x) x = a;
}
console.log(x);
