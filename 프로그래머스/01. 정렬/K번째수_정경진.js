function solution(array, commands) {
    var answer = [];
    for (let i=0; i<commands.length; i++) {
        let start = commands[i][0];
        let end = commands[i][1];
        let target = commands[i][2];
        let splitedArr = array.slice(start-1, end);
        splitedArr.sort((a, b)=> {
            return a-b;
        });
        answer.push(splitedArr[target-1]);
    }
    console.log(answer);
    return answer;
}