#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* functions */
int odd(int val);
int even(int val);
int filter(int (*func)(int), int *items, int *results, int n);

/* main */
int main(void) {
    int items[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int odds[9] = {0};
    int evens[9] = {0};
    int i, n;

    /* 配列の中身を表示 */
    printf("実行前: ");
    for ( i = 0; i < 9; i++ )  printf("%d ", items[i]);
    printf("\n");

    /* 偶数のデータのみを取得 */
    n = filter(odd, items, odds, 9);

    /* 結果を表示 */
    printf("奇数だけを取得: ");
    for ( i = 0; i < n; i++ ) printf("%d ", odds[i]);
    printf("\n");

    /* 奇数のデータのみを取得 */
    n = filter(even, items, evens, 9);

    /* 結果を表示 */
    printf("偶数だけを取得: ");
    for ( i = 0; i < n; i++ ) printf("%d ", evens[i]);
    printf("\n");

    return EXIT_SUCCESS;
}

/**
 * 奇数かどうかを判定する
 * @param[in] val 判定対象の値
 * @retval 真 奇数
 * @retval 偽 偶数
 */
int odd(int val) {
    if ( val & 1 ) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 偶数かどうかを判定する
 * @param[in] val 判定対象の値
 * @retval 真 偶数
 * @retval 偽 奇数
 */
int even(int val) {
    if ( !(val & 1) ) {
        return 1;
    } else {
        return 0;
    }
}

/**
 * 配列にフィルタをかけ, results に格納して返す.
 * @param[in] func int型の引数を1つもつ真偽値を返す関数へのポインタ
 * @param[in] items フィルターをかける配列
 * @param[out] results 結果を格納する配列
 * @param[in] n itemsの要素数
 * @return resultsの要素数
 */
int filter(int (*func)(int), int *items, int *results, int n) {
    int i, j = 0;

    for(i = 0; i < n; i++) {
        /* 真偽値を返す関数を実行 */
        if ( func(items[i]) ) {
            results[j++] = items[i];
        }
    }
    return j;
  }
