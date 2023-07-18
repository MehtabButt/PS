const minPathSum = function(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    const x=0, y=0
    const dir = [[0,1], [1,0]]
    const memo = {}

    function minPathSumUtil(x,y) {
        if(x==rows-1 && y==cols-1) return grid[x][y]
        if(memo[`${x},${y}`]) return memo[`${x},${y}`]
        let minSum = Infinity
        let newPos;
        for(d of dir) {
            newPos = [d[0]+x, d[1]+y]
            if(newPos[0] < rows && newPos[1] < cols) minSum = Math.min(minSum, minPathSumUtil(...newPos))
        }
        return memo[`${x},${y}`] = minSum+grid[x][y]
    }

    return minPathSumUtil(x,y);
};

const res = minPathSum([[1,3,1],[1,5,1],[4,2,1]])
console.log('res sum: ', res);
