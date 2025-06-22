#!/bin/bash

# コマンドが失敗したら、即座にスクリプトを終了する
set -e

# --- 表示用のカラーコード ---
GREEN="\033[0;32m"
RED="\033[0;31m"
BLUE="\033[0;34m"
RESET="\033[0m"

# --- 実行ファイル名 ---
PUSH_SWAP="./push_swap"

# --- 事前チェック ---
if [ ! -f "$PUSH_SWAP" ]; then
    echo -e "${RED}エラー: '$PUSH_SWAP' が見つかりません。先に 'make' を実行してください。${RESET}"
    exit 1
fi


# --- 手数チェック用の関数 ---
check_moves() {
    local COUNT=$1
    local MAX_MOVES=$2

    echo -n -e "Testing with ${BLUE}$COUNT${RESET} numbers... "

    # 【修正版】より安全な方法で、重複しないランダムな引数を生成
    local ARG=$(awk -v seed=$RANDOM 'BEGIN {
        srand(seed);
        count_target = '$COUNT';
        min = -2147483648;
        max = 2147483647;
        i = 0;
        while (i < count_target) {
            num = min + int(rand() * (max - min + 1));
            if (!(num in unique_nums)) {
                unique_nums[num] = 1;
                i++;
            }
        }
        for (n in unique_nums) printf "%d ", n;
    }')

    # push_swapを実行し、出力された命令の行数を数える
    local MOVES=$($PUSH_SWAP $ARG | wc -l | tr -d ' ')

    # 結果を表示
    if [ "$MOVES" -lt "$MAX_MOVES" ]; then
        echo -e "Moves: ${GREEN}$MOVES${RESET}"
    else
        echo -e "Moves: ${RED}$MOVES${RESET} (Threshold: < $MAX_MOVES)"
    fi
}


# --- メインのテスト処理 ---
echo -e "${BLUE}--- Running push_swap performance tests ---${RESET}"

check_moves 3 4
check_moves 5 13
check_moves 100 700
check_moves 500 5500

echo -e "\n${GREEN}--- Test script finished ---${RESET}"
