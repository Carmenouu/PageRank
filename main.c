#include "pr_etudiants.c"

int main()
{
  FILE *fp;
  SMAT *H;
  VEC  *r;
  VEC  *a;

  // On construit M
  fp = fopen( "genetic.dat", "r" );
  H = sm_input( fp );
  fclose( fp );
  sm_output( stdout, H );

  // On construit H à partir de M
  sm_convert(H);
  sm_output( stdout, H );

  // On construit r0 avec des probas égales (1/n)
  r = v_get(H->m);
  for (int i = 0; i < H->m; i++)
  {
  	r->e[i] = 1. / H->m;
  }
  v_output(stdout, r);

  // On construit a
  a = v_get(H->n);
  for (int i = 0; i < H->n; i++)
  {
    if (H->row[i].nnz == 0)
    {
      a->e[i] = 1;
    }
    else
    {
      a->e[i] = 0;
    }
  }
  v_output(stdout, a);

  // On définit alpha
  double alpha = 0.5;

  // Itérations
  for (int i = 0; i < 10; i++)
  {
  	r = new_r(r, H, a, alpha);
    v_output(stdout, r);
  }


  sm_free(H);
  v_free(r);

  return 0;
}