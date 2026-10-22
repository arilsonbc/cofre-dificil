#include <stdio.h>
#include <string.h>
#include <stdint.h>

static const unsigned char alvo[] = {119,77,251,168,220,195,87,59,112,73,194,87};
static unsigned char rot(unsigned char x, unsigned k) { return (unsigned char)((x<<k)|(x>>(8-k))); }
static int validar(const unsigned char *s, size_t n) {
    if (n != sizeof alvo) return 0;
    uint32_t estado=UINT32_C(0x6d2b79f5), diferenca=0;
    for (unsigned i=0; i<sizeof alvo; ++i) {
        unsigned idx=(i*5)%sizeof alvo;
        unsigned char x=(unsigned char)(s[idx] ^ (unsigned char)(estado>>((i%4)*8)));
        x=(unsigned char)(rot(x,(i%7)+1)+i*19);
        diferenca |= (uint32_t)(x ^ alvo[i]);
        estado=(estado ^ s[idx])*UINT32_C(1664525)+UINT32_C(1013904223);
    }
    return (diferenca == 0) & (estado == UINT32_C(4208086897));
}

int main(void) {
    unsigned char senha[128];
    puts("COFRE DIGITAL - NIVEL 3 (DIFICIL)");
    puts("Laboratorio educativo de engenharia reversa");
    printf("Digite a senha: ");
    fflush(stdout);
    if (!fgets((char *)senha,sizeof senha,stdin)) return 2;
    size_t n=strcspn((char *)senha,"\r\n");
    senha[n]=0;
    int ok=validar(senha,n);
    puts(ok ? "ACESSO LIBERADO! Voce abriu o cofre." : "ACESSO NEGADO! Senha incorreta.");
    puts("Pressione ENTER para sair.");
    getchar();
    return ok ? 0 : 1;
}
