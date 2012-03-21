N = c(10, 100, 1000, 10000, 100000, 1000000, 10000000);
langs = c("Go", "Python", "C++", "Java");
pchs = c("+", "x", "*", "o");
colors = c("red", "green", "black", "blue");

# Java
access_time = c(0.803400, 0.307150, 0.363706, 0.633317, 0.298482, 0.160155, 0.178708)

png("hashtable-rand-access.png", bg="transparent", width=700, height=500)
plot(N, access_time, type="o", pch="o", col="blue", log="x", ann=FALSE, lty=1, ylim=c(0,5));
title(ylab="Average Access Time (us/op)");
title(xlab="Number of Elements");

# Go
access_time = c(0.3, 0.11000000000000001, 0.087, 0.1141, 0.38335, 0.535501, 0.6896599);
lines(N, access_time, type="o", pch="+", lty=1, col="red");

# C++
access_time = c(0.4, 0.16, 0.168, 0.2055, 0.54728, 0.690345, 0.743512);
lines(N, access_time, type="o", lty=1, pch="*", col="black");

# Python
access_time = c(4.9, 0.54, 0.13, 0.121, 0.40927, 0.497939, 0.6353964);
lines(N, access_time, type="o", pch="x", lty=1, col="green");

legend(1e5, 4, langs, pch=pchs, col=colors)
title(main="Hash Table Access Time (Random Access Patern)");

dev.off();
