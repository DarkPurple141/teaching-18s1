<template lang="html">
   <section class="section-footer">
      <div class="footer-links">
         <div class="footer-link" v-for="item in items">
            <a :href="item.link">
               <div>
                  <icon scale="1.5" :name="item.icon"/>
               </div>
            </a>
         </div>
      </div>
      <div class="copyright">
         <p>Made by Alexander Hinds</p>
         <p>&#xa9; 2018</p>
      </div>
      <!--<h1>{{ longName }}</h1>-->
   </section>
</template>

<script>
export default {
   data() {
      return {
         items: [
            {
               link: 'https://github.com/DarkPurple141/teaching-18s1',
               name: 'Source.',
               icon: 'github'
            },
            {
               link: 'mailto:a.hinds@unsw.edu.au',
               name: 'Email.',
               icon: 'envelope'
            }
         ]
      }
   }
}
</script>

<style lang="less" scoped>
@import '../assets/colors.less';

.section-footer {
   display: flex;
   flex-direction: row;
   align-items: center;
   justify-content: center;
   width: 100%;
   bottom: -1px;
   position: fixed;
   height: 120px;
   background-color: #111;
   color: @grey-light;
   line-height: 1.5;
}

.footer-links {
   display: flex;
   flex-direction: column;
   align-items: center;
   justify-content: center;
   margin: auto;
   padding: 10px;
   width: 50%;
   border-right: 4px solid @accent;
}

.copyright {
   text-align: center;
   width: 50%;
   padding: 10px;
}

.footer-link {
   text-align: left;
   padding: 5px;
}

a {
   display: flex;
   justify-content: center;
   text-decoration: none;
   line-height: 1;
   color: inherit;
}

a:hover {
   color: @base-text;
}

@media screen and (max-width: 700px) {
   .section-footer {
      height: 150px;
      flex-direction: column;
   }

   .footer-links {
      flex-direction: row;
      border-right: none;
      border-bottom: 4px solid @accent;
   }
}

</style>
