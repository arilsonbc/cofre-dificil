# Solução — spoilers

Senha: `Nexus-7!Q4z?` (12 caracteres ASCII, respeitando maiúsculas e símbolos).

A leitura percorre (i*5)%12. A cada rodada, faz XOR com um byte do estado, rotaciona i%7+1 bits e soma i*19. A tabela valida o resultado; o estado seguinte depende do caractere original e usa multiplicação por 1664525 e soma de 1013904223, módulo 2^32. Inverta cada resultado na ordem das rodadas e atualize o estado antes da próxima. Ao final são verificados tanto os resultados acumulados quanto o estado.

Para o patch, localize o ponto que escolhe sucesso/falha após a validação, confirme com entradas diferentes e altere uma cópia. Não há offsets fixos neste guia: dependem da compilação. Um patch na mensagem isolada pode exibir sucesso sem alterar o código de saída; uma solução completa deve também retornar código 0.

O teste automatizado usa a senha correta, uma mutação em cada posição, entrada vazia, curta e longa. Ele não demonstra que você concluiu a análise manual no Ghidra ou x64dbg.
