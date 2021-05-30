package leetcode.weeklyrace._237;

import java.util.Random;

public class D {
    class Solution {
        public int getXORSum(int[] arr1, int[] arr2) {
            int a = 0;
            int b = 0;
            for (int value : arr1) {
                a ^= value;
            }
            for (int value : arr2) {
                b ^= value;
            }
            return a & b;
        }
    }

    public void washCard(int[] card) {
        Random random = new Random();
        for (int i = card.length - 1; i >= 0; i--) {
            int cardIndex = random.nextInt(i + 1);// �õ�[0, i]���������
            card[cardIndex] ^= card[i];
            card[i] ^= card[cardIndex];
            card[cardIndex] ^= card[i];
        }
    }
}
