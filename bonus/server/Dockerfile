#
# build addon
#
FROM node:18 as builder_addon

WORKDIR /app

COPY ./addons/ .

# install deps
RUN npm install

# build addon
RUN npm run build



#
# build corewar
#
FROM node:18 as builder_corewar

WORKDIR /app

COPY ./corewar .

RUN make


#
# build server
#
FROM node:18 as builder_server

WORKDIR /app

COPY package.json .
COPY package-lock.json .
COPY src ./src

RUN npm install


#
# production stage
#
FROM node:18 as app

WORKDIR /app

COPY --from=builder_addon /app/ ./addons/
COPY --from=builder_corewar /app/corewar .
COPY --from=builder_server /app/ .
COPY ./champions ./champions

EXPOSE 3000

ENTRYPOINT [ "npm", "run" ]

CMD [ "start" ]
