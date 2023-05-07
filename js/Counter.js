
//@param {number} n
//@return {Function} count

var createCounter = function(n) {
    let cur = n;

    return function() {
        return cur++;
    };
};


const counter = createCounter(10)
console.log(counter()) // 10
console.log(counter()) // 11
console.log(counter()) // 12

