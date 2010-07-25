import java.io.*;
import java.math.*;
import java.util.*;

public class b2
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		double eps = 1e-17;
		int T = in.nextInt();
		for( int num = 0; num < T; num++ )
		{
			int Ax = in.nextInt(), Ay = in.nextInt(), Bx = in.nextInt(), By = in.nextInt();
			double P = in.nextDouble(), Q = in.nextDouble(), R = in.nextDouble();
			
			// manhattan dist
			double man = Math.abs(Ax-Bx) + Math.abs(Ay-By);
			
			if( P!=0 && Q!=0 && Ax!=Bx && Ay!=By )
			{
				Bx -= Ax; By -= Ay;
				R -= P*Ax+Q*Ay;
				Ax = Ay = 0;
				if( Bx<0 )
				{
					Bx = -Bx;
					P = -P;
				}
				if( By<0 )
				{
					By = -By;
					Q = -Q;
				}
				boolean slope = -P/Q > 0;
				if( slope )
				{
					double minxi = R/Q, maxxi = (R-P*Bx)/Q, minyi = R/P, maxyi = (R-Q*By)/P;
					boolean left = minxi+eps>=0 && minxi-eps<=By;
					boolean right = maxxi+eps>=0 && maxxi-eps<=By;
					boolean bottom = minyi+eps>=0 && minyi-eps<=Bx;
					boolean top = maxyi+eps>=0 && maxyi-eps<=Bx;
					if( left || right || bottom || top )
					{
						double Cx = 0, Cy = 0, Dx = Bx, Dy = By;
						if( left ) Cy = minxi;
						if( bottom ) Cx = minyi;
						if( top ) Dx = maxyi;
						if( right ) Dy = maxxi;
						double Ex = Dx-Cx, Ey = Dy-Cy;
						man = Cx+Cy+Bx-Dx+By-Dy+Math.sqrt(Ex*Ex+Ey*Ey);
					}
				}
			}
			System.out.println(man);
		}
	}
}
