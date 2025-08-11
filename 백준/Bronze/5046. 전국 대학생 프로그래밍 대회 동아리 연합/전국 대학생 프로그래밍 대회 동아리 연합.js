const input = require('fs').readFileSync(0, 'utf-8').trim().split('\n');

let [n, b, h, w] = input[0].split(' ').map(Number);

let res = 10101010;
for (let i = 1; i<=h; i++) {
    let cost = input[2*i-1];
    let valid = input[2*i].split(' ').map(Number);

    let tot = cost*n;
    for (let j = 0; j<w; j++) {
        if (valid[j] >= n) {
            res = Math.min(res, tot);
        }
    }
}

if (res <= b) console.log(res);
else console.log("stay home");