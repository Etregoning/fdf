int main (void)
{
	/* 
	start of line = (x1, y1);
	end of line = (x2, y2);
	y = mx + b;
	m = (rise / run);
	m = ( (diff in y) / (diff in x))
		((y2 - y1) / (x2 - x1));
	now you can find the correct 'y' for any given 'x'

		y1 = m * x1 + b
		y1 - (m * x1) = b;*/
	diff = (m * x + b) - (m * (x + 1) + b);
	while (x < end_of_line)
	{
		mlx_pixel_put(x, y, color);
		y += diff;
		x++;
	}
}
