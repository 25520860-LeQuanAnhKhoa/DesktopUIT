// HAM GIUP NGUOI CHOI TANG DIEM KHI CHO BLOCKS ROI NHANH
void addDropScore(int distance, bool hardDrop) {

    if (hardDrop)
        score += distance * 2;

    else
        score += distance;
}

// CAN THEM VA SUA  VAO MAIN

int main () {
     // SOFT DROP
            else if (c == 's') {

                if (canMove(0, 1)) {

                    y++;

                    addDropScore(1, false);

                    soundDrop();
                }
            }
        // HARD DROP
            else if (c == ' ') {

                int dropDistance = 0;

                while (canMove(0, 1)) {

                    y++;

                    dropDistance++;
                }

                addDropScore(dropDistance, true);

                soundDrop();
            }

}
