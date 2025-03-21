# Vetor original
valores <- c(590, 815, 575, 608, 350, 1285, 408, 540, 555, 679)

# Função para calcular a mediana aparada
trimmed_median <- function(x, trim = 0.2) 
{
  n <- length(x)
  k <- floor(n * trim)  # Número de elementos a remover de cada lado
  x_sorted <- sort(x)
  # Removendo os k menores e os k maiores valores
  trimmed <- x_sorted[(k + 1):(n - k)]
  median(trimmed)
}

# Cálculo dos valores iniciais
cat("Média original:", mean(valores), "\n")
cat("Mediana original:", median(valores), "\n")

# Alteração: substituindo o sexto elemento (1285) por 985
valores[6] <- 985

cat("Média após alteração:", mean(valores), "\n")
cat("Mediana após alteração:", median(valores), "\n")

# Cálculo da média aparada utilizando a função built-in 'mean' com o parâmetro trim
media_aparada20 <- mean(valores, trim = 0.2)  # 20% aparado
media_aparada15 <- mean(valores, trim = 0.15) # 15% aparado

# Cálculo da mediana aparada utilizando a função definida 'trimmed_median'
mediana_aparada20 <- trimmed_median(valores, trim = 0.2)
mediana_aparada15 <- trimmed_median(valores, trim = 0.15)

# Exibição dos resultados de médias e medianas aparadas
cat("Média aparada 20%:", media_aparada20, "\n")
cat("Mediana aparada 20%:", mediana_aparada20, "\n")
cat("Média aparada 15%:", media_aparada15, "\n")
cat("Mediana aparada 15%:", mediana_aparada15, "\n")
