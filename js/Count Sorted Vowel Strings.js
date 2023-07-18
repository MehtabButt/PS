var countVowelStrings = function (n) {
    return (Math.pow(n+1,4) + 6*Math.pow(n+1,3) + 11*Math.pow(n+1,2) + 6*(n+1)) / 24
};

console.log(countVowelStrings(1))
console.log(countVowelStrings(2))
console.log(countVowelStrings(33))
