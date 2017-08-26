package threads;
import java.util.concurrent.*;


public class Driver3 {
	public static DropBox dropbox = new DropBox();
	public static void main(String[] args) {
		ExecutorService executor = Executors.newFixedThreadPool(2);
		executor.execute(new Producer(dropbox));
		executor.execute(new Consumer(dropbox));
		executor.shutdown();
		while(!executor.isTerminated()){}
		System.out.println("Complete " + Thread.currentThread().getName());
	}
	
	public static class Producer implements Runnable {
		private DropBox dropbox;
		public Producer(DropBox dropbox) {
			this.dropbox = dropbox;
		}
		public void run() {
			
			Product product = new Product();
			System.out.println(dropbox.put(product));
			System.out.println("Placed1 " + Thread.currentThread().getName() + " Producer");
			try {
				Thread.sleep(2000);
				Product product1 = new Product();
				
				System.out.println(dropbox.put(product1));
				System.out.println("Placed2 " + Thread.currentThread().getName() + " Producer");
			}catch(InterruptedException e){}
			
			
		}
		
	}
	public static class Consumer implements Runnable {
		private DropBox dropbox;
		public Consumer(DropBox dropbox) {
			this.dropbox = dropbox;
		}
		public void run() {
			System.out.println(dropbox.take());
	
			System.out.println("Taken1 " + Thread.currentThread().getName() + " Consumer");
			try {
				Thread.sleep(2000);
				
				System.out.println(dropbox.take());
				System.out.println("Taken2 " + Thread.currentThread().getName() + " Consumer");
			}catch(InterruptedException e){}
		}
	}
	public static class Product{}
	public static class DropBox {
		Product product;
		boolean isFull = false;
		public synchronized String put(Product product) {
			while(isFull) {
				try {
					wait();
				}catch(InterruptedException e){}
			}
			isFull = true;
			this.product = product;
			notifyAll();
			return "putting..";
		}
		
		public synchronized String take() {
			while(!isFull) {
				try {
					wait();
				}catch(InterruptedException e){}
			}
			isFull = false;
			product = null;
			notifyAll();
			return "taking..";
		}
	}
}
