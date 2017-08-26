package threads;

import java.util.concurrent.*;

public class ThreadsExecutorService {
	public static void main(String[] args) {
		ExecutorService executor = Executors.newFixedThreadPool(10);
		// submit each thread
		for (int i = 0; i < 10; i++) {
			executor.submit(new MyRunnable(i + 1));
		}
		executor.shutdown();
	}

	private static class MyRunnable implements Runnable {
		private int numJobs;

		public MyRunnable(int numJobs) {
			this.numJobs = numJobs;
		}

		public void run() {
			long sleepTime = (long) (Math.random() * 10000) + 1000;
			try {
				Thread.sleep(sleepTime);
				System.out.format("Complete. Job number %2d of %16s. I slept for %2d seconds.\n", numJobs,
						Thread.currentThread().getName(), sleepTime / 1000);
			} catch (InterruptedException e) {
				System.out.println(Thread.currentThread().getName() + " was interrupted.");
				e.printStackTrace();
			}

		}
	}

}