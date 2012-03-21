N = c(10, 100, 1000, 10000, 100000, 1000000, 10000000);
langs = c("Go", "Python", "C++", "Java");
pchs = c("+", "x", "*", "o");
colors = c("red", "green", "black", "blue");
access_time = c(8.751800, 1.613250, 0.815325, 1.555751, 0.219468, 0.073412, 0.061496)

png("hashtable-seq-access.png", bg="transparent", width=700, height=500)
plot(N, access_time, type="o", pch="o", col="blue", log="x", ann=FALSE, lty=1);
title(ylab="Average Access Time (us/op)");
title(xlab="Number of Elements");

access_time = c(0.4000000000000001, 0.14, 0.12300000000000001, 0.119, 0.15627000000000002, 0.17811000000000002, 0.2497328);
lines(N, access_time, type="o", pch="+", lty=1, col="red");

access_time = c(0.2, 0.14, 0.166, 0.1946, 0.36684, 0.392766, 0.471303);
lines(N, access_time, type="o", lty=1, pch="*", col="black");

access_time = c(4.6, 0.51, 0.143, 0.1143, 0.26562, 0.331683, 0.3797068);
lines(N, access_time, type="o", pch="x", lty=1, col="green");

legend(1e5, 6, langs, pch=pchs, col=colors)
title(main="Hash Table Access Time (Sequential Access Patern)");

dev.off();
