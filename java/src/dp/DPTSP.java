package dp;

/**
 * TSP的动态规划算法
 * @author yinchuandong
 *
 */
public class DPTSP {
	
	public static void tsp(){
		/**
		 * 距离矩阵
		 */
		int[][] D = {
				{0 , 10, 20, 30, 40, 50},
				{12, 0 , 18, 30, 25, 21},
				{23, 19, 0 ,  5, 10, 15},
				{34, 32, 4 ,  0,  8, 16},
				{45, 27, 11, 10, 0 , 18},
				{56, 22, 16, 20, 12, 0 }
		};
		
		int n = D.length;
		int i, j, k, min, temp;
		int b = (int)Math.pow(2, n - 1);
		
		int[][] F = new int[n][b];
		int[][] M = new int[n][b];
	
		for(i = 0; i < b; i++){
			for(j = 0; j < n; j++){
				F[j][i] = -1;
				M[j][i] = -1;
			}
		}
		
		for(j = 0; j < n; j++){
			F[j][0] = 0;
		}
		
		for(i = 1; i < b - 1; i++){
			for(j = 1; j < n; j++){
				int p = (int)Math.pow(2, j - 1);
				int t = p & i;
				if(t == 0){
//					System.out.println("i=" + i + " j=" + j);
					min = Integer.MAX_VALUE;
					for(k = 1; k < n; k++){
						int kId = (int)Math.pow(2, k - 1);
						if((kId & i) != 0){
							temp = D[j][k] + F[k][i - kId];
							if(temp < min){
								min = temp;
								F[j][i] = min;
								M[j][i] = k;
							}
									
						}
					}
					
				}
			}
		}
		
		
		min = Integer.MAX_VALUE;
		for(k = 1; k < n; k++){
			int kId = (int)Math.pow(2, k - 1);
			temp = D[0][k] + F[k][b - 1 - kId];
			if (temp < min) {
				min = temp;
				F[0][b - 1] = min;
				M[0][b - 1] = k;
			}
		}
		System.out.println("the shortest length is: " + F[0][b - 1]);
		
		System.out.println("the route is: " );
		System.out.print("0");
		for(i = b - 1, j = 0; i > 0; ){
			j = M[j][i];
			i = i - (int)Math.pow(2, j - 1);
			System.out.print("->" + j);
		}
		
		System.out.println();
		for(i = 0; i < n; i++){
			for(j = 0; j < b; j++){
				System.out.print(F[i][j] + " ");
			}
			System.out.println();
		}
		
	}
	
	public static void main(String[] args){
		long start = System.currentTimeMillis();
		
		tsp();
	
		long end = System.currentTimeMillis();
		
		long delay = end - start;
		System.out.println(" time consuming: " + delay + "ms");
		
		

	}
	
	
	
	
	
}
