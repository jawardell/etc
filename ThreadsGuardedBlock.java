package threads;

public class ThreadsGuardedBlock {
	public static void main(String[] args) {
		Thread thread = new Thread(new MyRunnable(0));
		thread.start();
		Thread thread2 = new Thread(new MyRunnable(5));
		thread2.start();

	}

	private static class MyRunnable implements Runnable {
		private int numIterations;
		private int numJobs;

		public MyRunnable(int numJobs) {
			numIterations = 0;
			this.numJobs = numJobs;
		}

		public boolean isCountDone() {
			if (numIterations == Integer.MIN_VALUE) {
				return false;
			}
			return numIterations >= 5;
		}

		public void run() {
			while (!isCountDone()) {
				numIterations += 1;
				numJobs += 1;
				long sleepTime = (long) (Math.random() * 10000) + 1000;
				try {
					Thread.sleep(sleepTime);
					System.out.format("Complete. Job number %2d of %2s. I slept for %2d seconds.\n", numJobs,
							Thread.currentThread().getName(), sleepTime / 1000);
				} catch (InterruptedException e) {
					System.out.println(Thread.currentThread().getName() + " was interrupted.");
					e.printStackTrace();
				}
			}
		}
	}
}