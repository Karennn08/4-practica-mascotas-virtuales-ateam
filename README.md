[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/_T9NCoa5)
# 4.-Pr-ctica-Mascotas-Virtuales

El diagrama representa un sistema de mascotas virtuales basado en un enfoque orientado a objetos. La clase principal es **Servidor**, la cual administra el sistema y tiene como atributos el nombre, el país y listas de usuarios, objetos y habilidades. Entre sus métodos, permite registrar y mostrar habilidades, objetos y usuarios. El servidor ofrece estos elementos a los usuarios y los contiene en su sistema.

La clase **Usuario** representa a las personas que interactúan con el sistema. Tiene atributos como el nombre, el identificador (ID) y listas de mascotas y objetos. Los métodos asociados a esta clase permiten adoptar mascotas, usar y agregar objetos, mostrar las mascotas y consultar el historial. Un usuario puede tener múltiples mascotas y objetos, y cada usuario está contenido en el servidor.

Las mascotas están representadas por la clase **Mascota**, que incluye atributos como el nombre, la edad, la experiencia, la energía, el estado de salud, el ánimo, una lista de habilidades y un historial. Esta clase tiene métodos para actualizar el estado, ganar experiencia, mostrar habilidades e historial, y aprender nuevas habilidades. Cada mascota puede obtener múltiples habilidades y recibir múltiples cuidados.

La clase **Objeto** representa los elementos que los usuarios pueden utilizar en las mascotas. Tiene como atributos el nombre, el tipo y el efecto que produce. Sus métodos permiten aplicar el efecto a una mascota y mostrar la información del objeto. Los usuarios pueden poseer múltiples objetos, y el servidor ofrece estos objetos para su uso.

La clase **Habilidad** define las capacidades que una mascota puede aprender. Sus atributos incluyen el nombre, la descripción y la experiencia requerida para adquirir la habilidad. Esta clase tiene un método que verifica si una mascota puede aprender una habilidad en función de su experiencia. Cada mascota puede obtener múltiples habilidades a lo largo del tiempo.

Finalmente, la clase **Cuidado** registra las acciones realizadas para mantener la salud de las mascotas. Tiene como atributos la fecha, el tipo de cuidado, el objeto utilizado y el estado de salud resultante. Su único método permite mostrar la información del cuidado. Cada mascota puede recibir múltiples cuidados a lo largo de su existencia.
