void ft_putendl_fd(charconst*s,intfd);
{
	write(fd, c, ft_strlen(s));
	write(fd, "\n", 1);
}