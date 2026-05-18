// ==========================================
// GET COLOR
// ==========================================

int getColor(char c) {

    switch (c) {

    case 'I': return 11; // Cyan
    case 'O': return 14; // Yellow
    case 'T': return 13; // Purple
    case 'S': return 10; // Green
    case 'Z': return 12; // Red
    case 'J': return 9;  // Blue
    case 'L': return 6;  // Orange
    case '#': return 7;  // Gray wall

    default: return 15;  // White
    }
}

// ==========================================
// DRAW WITH COLOR (FINAL)
// ==========================================


// SỬA LẠI HÀM draw() ĐỂ PHÙ HỢP VƠI HÀM getColor

void draw() {

    static char buffer[H][W];

    // Copy board vào buffer
    for (int i = 0; i < H; i++) {

        for (int j = 0; j < W; j++) {

            buffer[i][j] = board[i][j];
        }
    }

    // Add current piece vào buffer
    auto s = shape();

    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {

            if (s[i][j] != ' ') {

                int ty = y + i;
                int tx = x + j;

                if (ty >= 0 && ty < H &&
                    tx >= 0 && tx < W) {

                    buffer[ty][tx] = s[i][j];
                }
            }
        }
    }

    // Vẽ từ góc trên trái
    gotoxy(0, 0);

    int lastColor = 15;

    // Draw board
    for (int i = 0; i < H; i++) {

        for (int j = 0; j < W; j++) {

            char c = buffer[i][j];

            // Ô trống
            if (c == ' ') {

                if (lastColor != 15) {

                    setColor(15);
                    lastColor = 15;
                }

                cout << "  ";
            }

            // Ô có block
            else {

                int color = getColor(c);

                if (color != lastColor) {

                    setColor(color);
                    lastColor = color;
                }

                cout << "[]";
            }
        }

        // Reset màu cuối dòng
        if (lastColor != 15) {

            setColor(15);
            lastColor = 15;
        }

        cout << endl;
    }

    // UI
    setColor(15);

    cout << "\n========== TETRIS ==========\n";

    cout << "SCORE : " << score << endl;
    cout << "SPEED : " << speed << endl;

    cout << "MODE  : ";

    if (gameMode == 1)
        cout << "EASY\n";
    else
        cout << "HARD\n";

    cout << "\nA : LEFT\n";
    cout << "D : RIGHT\n";
    cout << "S : DOWN\n";
    cout << "W : ROTATE\n";
    cout << "SPACE : HARD DROP\n";
    cout << "P : PAUSE\n";
    cout << "Q : QUIT\n";
}
