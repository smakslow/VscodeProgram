package leetcode.weeklyrace._237;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class C {
    class Solution {
        class Task {
            int enqueueTime;
            int processingTime;
            int index;

            public Task(int enqueueTime, int processingTime, int index) {
                this.enqueueTime = enqueueTime;
                this.processingTime = processingTime;
                this.index = index;
            }
        }

        public int[] getOrder(int[][] tasks) {
            PriorityQueue<Task> pq = new PriorityQueue<>((o1, o2) -> {
                if (o1.processingTime == o2.processingTime) {
                    return o1.index - o2.index;
                }
                return o1.processingTime - o2.processingTime;
            });
            Task[] arr = new Task[tasks.length];
            for (int i = 0; i < tasks.length; i++) {
                arr[i] = new Task(tasks[i][0], tasks[i][1], i);
            }
            Arrays.sort(arr, Comparator.comparingInt(o -> o.enqueueTime));
            int begin = 0;
            int start = 0;
            int[] res = new int[tasks.length];
            int index = 0;
            while (!pq.isEmpty() || start < arr.length) {
                if (pq.isEmpty()) {
                    begin = Math.max(begin, arr[start].enqueueTime);
                }
                while (start < arr.length && begin >= arr[start].enqueueTime) {
                    pq.offer(arr[start++]);
                }
                Task task = pq.poll();
                res[index++] = task.index;
                begin += task.processingTime;

            }
            return res;
        }
    }
}
