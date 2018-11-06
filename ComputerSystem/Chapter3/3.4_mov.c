typedef char src_t;
typedef long dest_t;

void mov(src_t *sp, dest_t *dp)
{
	*dp = (dest_t) *sp;
}
