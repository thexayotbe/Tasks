vector<int> minOperations(string boxes) {
    int n = boxes.size();
    vector<int> answer(n, 0);

    // Left-to-right pass
    int leftSum = 0;       // Sum of indices of '1's on the left
    int leftFreq = 0;      // Count of '1's on the left
    for (int i = 0; i < n; ++i) {
        answer[i] += leftSum;  // Add operations needed for left '1's
        if (boxes[i] == '1') {
            leftFreq++;
        }
        leftSum += leftFreq;  // Increase the distance for next step
    }

    // Right-to-left pass
    int rightSum = 0;       // Sum of indices of '1's on the right
    int rightFreq = 0;      // Count of '1's on the right
    for (int i = n - 1; i >= 0; --i) {
        answer[i] += rightSum;  // Add operations needed for right '1's
        if (boxes[i] == '1') {
            rightFreq++;
        }
        rightSum += rightFreq;  // Increase the distance for next step
    }

    return answer;
}
