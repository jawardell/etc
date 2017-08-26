package threads;

public class TenThreads {
	public static int count = 0;

	public static void main(String[] args) {
		/*
		 * "Write a program that starts 10 jobs of random duration in 10 threads
		 * and prints out the order they finish in. Note that the jobs don't
		 * have to do anything, just sleep. You should probably define an
		 * instance variable to specify the order, which is defined when
		 * created."
		 * 
		 */
		for (int i = 0; i < 10; i++) {
			long sleepTime = (long) (Math.random() * 10000) + 1000;
			Thread t = new Thread(new CustomJob(i, sleepTime));
			t.start();
		}
	}

	private static class CustomJob implements Runnable {
		int jobId;
		long sleepTime;

		public CustomJob(int jobId, long sleepTime) {
			this.jobId = jobId;
			this.sleepTime = sleepTime;
			count += 10;
		}

		public void run() {

			try {
				jobId += 1;
				Thread.sleep(sleepTime);
				System.out.format("Complete. Job %2d of %2s. I slept for %2d seconds.\n", jobId,
						Thread.currentThread().getName(), sleepTime / 1000);

			} catch (Exception e) {
				System.out.println(Thread.currentThread().getName() + " was interrupted.");
				e.printStackTrace();
			}
		}
	}
}