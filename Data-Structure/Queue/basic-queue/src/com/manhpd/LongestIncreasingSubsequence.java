package com.manhpd;

import java.util.Stack;

public class LongestIncreasingSubsequence {

    public static void main(String[] args) {
//        int[] nums = {10, 9, 2, 5, 3, 7, 101, 18};
//        int[] nums = {0, 1, 0, 3, 2, 3};
//        int[] nums = {7, 7, 7, 7, 7, 7, 7};
//        int[] nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
//        int[] nums = {1, 0, 1, 0, 3, 2, 3};
//        int[] nums = {3, 5, 6, 2, 5, 4, 9, 5, 6, 7, 8};
        int[] nums = {3, 10, 2, 1, 20};

        LongestIncreasingSubsequence solution = new LongestIncreasingSubsequence();
        int res = solution.lengthOfLISIII(nums);
        System.out.println(res);
    }

    public int lengthOfLIS(int[] nums) {
        Stack<Integer> res = new Stack<>();
        res.add(nums[0]);
        int max = 1;

        for (int i = 1; i < nums.length; ++i) {
            while (!res.isEmpty()) {
                int last = res.peek();
                if (!res.contains(nums[i]) && last >= nums[i]) {
                    res.pop();
                } else {
                    break;
                }
            }

            if (res.contains(nums[i])) {
                continue;
            }

            res.push(nums[i]);
            max = Math.max(max, res.size());
        }

        return max;
    }

    /**
     * Use BST to solve
     * @param nums
     * @return
     */
    public int lengthOfLISI(int[] nums) {
        LisBst bst = new LisBst();
        int max = 1;
        bst.root = bst.add(nums[0], -1, bst.root);

        for (int i = 1; i < nums.length; ++i) {
            currentMax = 1;
            bst.add(nums[i], -1, bst.root);
            if (currentMax > max) {
                max = currentMax;
            }
        }

        return max;

    }

    private int currentMax = 1;

    private class LisBstNode {
        public int key;
        public int max;
        public int pre;
        public LisBstNode left, right;

        public LisBstNode(int key, int max, int pre, LisBstNode left,
                          LisBstNode right) {
            this.key = key;
            this.max = max;
            this.pre = pre;
            this.left = left;
            this.right = right;
        }
    }

    private class LisBst {
        private LisBstNode root;

        public LisBstNode add(int key, int pre, LisBstNode node) {
            if (node == null) {
                return new LisBstNode(key, currentMax, pre,
                        null, null);
            } else if (key > node.key) {
                if (currentMax < node.max + 1) {
                    currentMax = node.max + 1;
                }

                node.right = this.add(key, node.key, node.right);
            } else {
                node.left = this.add(key, node.key, node.left);
                if (currentMax > node.max) {
                    node.max = currentMax;
                }
            }

            return node;
        }
    }

    /**
     * Using brute-force solution
     *
     * @param nums
     * @return
     */
    public int lengthOfLISIII(int[] nums) {
        int leng = nums.length;
        int[] L = new int[leng];
        int[] tracker = new int[leng];

        for (int i = 1; i < leng; ++i) {
            int lmax = 0;
            int jmax = -1;

            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && lmax < L[j]) {
                    lmax = L[j];
                    jmax = j;
                }
            }

            L[i] = lmax + 1;
            tracker[i] = jmax;
        }

        return L[leng - 1];
    }
}
