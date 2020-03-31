function solution(citations) {
    var answer = 0;
    citations.sort((a, b) => {
        return b-a;
    });
    for (let i in citations) {
        if (citations[i] <= answer)
            break;
        answer++;
    }
    return answer;
};