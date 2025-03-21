U <- c(6.0,5.0,11.0,33.0,4.0,5.0,80.0,18.0,35.0,17.0,23.0);
R <- c(4.0,14.0,11.0,9.0,9.0,8.0,4.0,20.0,5.0,8.9,21.0,9.2,3.0,2.0,0.3)

cat("Media Amostral de U: ",mean(U),"\n");
cat("Media Amostral de R: ",mean(R),"\n");

cat("Mediana Amostral de U",median(U),"\n");
cat("Mediana Amostral de R",median(R),"\n");

trim_U <- 1/length(U)  # Para U: 1/11
trim_R <- 1/length(R)  # Para R: 1/15

cat("Media Amostral de U Aparada em 1 Valor: ",mean(U,trim = trim_U),"\n");
cat("Media Amostral de R: Aparada em 1 Valor ",mean(R,trim = trim_R),"\n");

cat("\n---------------------------------------------------------------------------------------------------------\n");

Mercurio <-c(0.2,0.22,0.3,0.34,0.41,0.55,0.56,1.42,1.70,1.83,2.2,2.25,3.07,3.25);

cat("Soma total de Mercurio: ",sum(Mercurio),"\n");
cat("Média amostral de Mercurio: ",mean(Mercurio),"\n");
cat("Mediana Amostral de Mercurio: ",median(Mercurio),"\n");
cat("\n\n");
cat("Media Amostral aparada em 10%: ",mean(Mercurio,trim = 0.1),"\n\n\n");
