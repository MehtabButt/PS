const strStr = function(haystack, needle) {
    let i=0;

    function isExists(idx) {
        for(let c of needle) {
            if(c != haystack[idx]) return false;
            ++idx;
        }
        return true;
    }

    while((haystack.length-i) >= needle.length) {
        if(needle[0] != haystack[i]) {
            ++i;
            continue;
        }
        if(isExists(i)) return i;
        ++i;
    }
    return -1;
}

let res = indexOfFirstOccurrence("sadbutsad", "sad")
console.log('result: ', res);

