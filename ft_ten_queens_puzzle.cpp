/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hirokiurabe <hirokiurabe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 22:02:40 by hirokiurabe       #+#    #+#             */
/*   Updated: 2025/02/09 23:02:41 by hirokiurabe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ten_queens_puzzle.hpp"
using namespace std;

static void solve(int col, int board[], int &count) {
    // すべての列（0〜9）にクイーンを配置できたら解として出力する
    if (col == 10) {
        for (int i = 0; i < 10; i++)
            cout << board[i];
        cout << endl;
        count++;
        return ;
    }
    for (int row = 0; row < 10; row++) {
        bool safe = true;
         // すでに配置した各クイーンとの衝突をチェックする
         for (int prev = 0; prev < col; prev++) {
            // 同じ行にあるか、斜め方向にある場合は配置は不可
            if (board[prev] == row || abs(board[prev] - row) == col - prev) {
                safe = false;
                break;
            }
         }
         // 衝突がなければ、現在の列にクイーンを配置して次の列へ進む
         if (safe) {
            board[col] = row;
            solve(col + 1, board, count);
         }
    }
}

// 全解を出力した上で解の総数を返す関数
int ft_ten_queens_puzzle(void) {
    int board[10]; // board[i]がi列目のクイーンの番号
    int count = 0; // 解の数
    solve(0, board, count);
    return count;
}

int main(void) {
    cout << ft_ten_queens_puzzle();
    return 0;
}
