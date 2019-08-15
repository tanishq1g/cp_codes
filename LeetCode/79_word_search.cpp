class Solution {
public:

// DFS BACKTRACKING
// each step is find letter at pos
bool findWord(vector< vector<char> >& board, string word, int i, int j, int pos) {
	// found
	if (pos == word.length()) return true;
	// not foud
	if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
	// visited or not wanted. (we mark the visited position as '*')
	if (word[pos] != board[i][j] || board[i][j] == '*') return false;
	// begin search
	char letter = board[i][j]; 
	board[i][j] = '*';
	bool isFound = 
		findWord(board, word, i + 1, j, pos + 1) ||
		findWord(board, word, i - 1, j, pos + 1) ||
		findWord(board, word, i, j + 1, pos + 1) ||
		findWord(board, word, i, j - 1, pos + 1);
	board[i][j] = letter; // reset
	return isFound;
}
    bool exist(vector<vector<char>>& board, string word) {
        if (!board.size()) return false;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[0].size(); ++j) {
			if (findWord(board, word, i, j, 0)) return true;
		}
	}
	return false;
    }
};