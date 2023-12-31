question : https://practice.geeksforgeeks.org/problems/find-the-string-in-grid0111/1
// This function searches for the word in the grid starting from position (i, j).
vector<int> solve(vector<vector<char>>& grid, int i, int j, string word) {
    int n = grid.size();
    int m = grid[0].size();
    string s = "";

    // Search horizontally to the right (hr)
    for (int st = j; st < m; st++) {
        if (s.length() == word.length()) {
            break;
        }
        s.push_back(grid[i][st]);
    }
    if (s == word) {
        return {i, j};
    }

    // Search horizontally to the left (hl)
    s = "";
    for (int st = j; st >= 0; st--) {
        if (s.length() == word.length()) {
            break;
        }
        s.push_back(grid[i][st]);
    }
    if (s == word) {
        return {i, j};
    }

    // Search vertically up (vu)
    s = "";
    for (int st = i; st >= 0; st--) {
        if (s.length() == word.length()) {
            break;
        }
        s.push_back(grid[st][j]);
    }
    if (s == word) {
        return {i, j};
    }

    // Search vertically down (vd)
    s = "";
    for (int st = i; st < n; st++) {
        if (s.length() == word.length()) {
            break;
        }
        s push_back(grid[st][j]);
    }
    if (s == word) {
        return {i, j};
    }

    // Search diagonally up and to the left (dul)
    s = "";
    int r = i, c = j;
    while (r >= 0 && c >= 0) {
        if (s.length() == word.length()) {
            break;
        }
        s.push_back(grid[r][c]);
        r--;
        c--;
    }
    if (s == word) {
        return {i, j};
    }

    // Search diagonally up and to the right (dur)
    s = "";
    r = i;
    c = j;
    while (r >= 0 && c < m) {
        if (s.length() == word.length()) {
            break;
        }
        s.push_back(grid[r][c]);
        r--;
        c++;
    }
    if (s == word) {
        return {i, j};
    }

    // Search diagonally down and to the left (ddl)
    s = "";
    r = i;
    c = j;
    while (r < n && c >= 0) {
        if (s.length() == word.length()) {
            break;
        }
        s.push_back(grid[r][c]);
        r++;
        c--;
    }
    if (s == word) {
        return {i, j};
    }

    // Search diagonally down and to the right (ddr)
    s = "";
    r = i;
    c = j;
    while (r < n && c < m) {
        if (s.length() == word.length()) {
            break;
        }
        s.push_back(grid[r][c]);
        r++;
        c++;
    }
    if (s == word) {
        return {i, j};
    }

    // If the word is not found in any direction, return {-1, -1}.
    return {-1, -1};
}

// This function searches for the word in the grid and returns a vector of positions.
vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
    vector<vector<int>> ans;
    int n = grid.size();
    int m = grid[0].size();

    // Iterate through the grid.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == word[0]) {
                // If the first letter of the word is found, try to find the word starting from this position.
                vector<int> temp = solve(grid, i, j, word);
                if (temp[0] != -1) {
                    ans.push_back(temp);
                }
            }
        }
    }
    
    return ans;
}
